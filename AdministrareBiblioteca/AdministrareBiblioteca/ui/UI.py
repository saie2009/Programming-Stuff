from repository.RepositoryCarte import RepositoryCarte
from controller.Controller import Controller
from model.Carte import Carte
from model.Persoana import Persoana
import random
class UI:

    def __init__(self, controller):
        self._controller=controller;
    
    def run(self):
       print("Bine ati venit !")
       print("Apasati tasta 0 pentru a vedea lista de optiuni")
       while True:
            n = input("Va rugam alegeti optiunea\n")
            if n=="0":
                print ("Optiunile dumneavoastra sunt:")
                print ("1.Adaugarea unei noi carti in baza de date")
                print ("2.Stergerea unei carti din baza de date")
                print ("3.Imprumutarea unei carti")
                print ("4.Vizualizarea listei de carti existente in baza de date")
                print ("5.Vizualizarea listei de clienti existenti in baza de date")
                print ("6.Vizualizarea a diferite rapoarte")
                print ("7.Iesire")
            if n=="1":
                print ("Vom adauga o noua carte la baza de date...")
                id = input("ID-ul noii carti: ")
                numeCarte = input("Numele cartii: ")
                numeAutor = input("Numele autorului: ")         #NU SUNT FACUTE VALIDARI DE DATE PENTRU ADAUGARE
                anulAparitiei = input("Anul aparitiei: ")
                pretCarte = input("Pretul cartii: ")
                editura = input("Editura cartii: ")
                cota = input("Cota cartii: ")
                numarInventar = input("Numar inventar: ")
                imprumutata = "Nu"
                nrImprumuturi = 0
                self._controller.addCarte(Carte(int(id),numeCarte,numeAutor,int(anulAparitiei),int(pretCarte),editura,int(cota),int(numarInventar),imprumutata,nrImprumuturi))
            if n=="2":
                print ("Vom sterge o carte din baza de date")
                id = input("ID-ul cartii: ")
                print(self._controller.deleteCarte(int(id)))
            if n=="3":
                print("Imprumutati o carte...")
                print("Sunteti deja clientul nostru ? Da/Nu")
                idPers = 0
                client = input()
                if client == "Da":
                    nume = input("Introduceti-va numele: ")
                    for persoana in self._controller.getListaPersoane():
                        if persoana.getNume() == nume:
                            idPers = persoana.getId()
                            if persoana.getIdCarte() != 0:
                                print("NU AVETI VOIE SA IMPRUMUTATI O NOUA CARTE PANA NU O RETURNATI PE ULTIMA LUATA !!!")
                                return
                if client == "Nu":
                    print ("Deoarece nu sunteti clientul nostru vom avea nevoie de datele dumneavoastra")
                    nume = input("Introduceti-va numele: ")
                    idPers = random.random()*100 #generarea unui nr random pt id cumprins intre 1-100
                    persoana = Persoana(idPers,nume,0,0)
                    self._controller.addPersoana(persoana)
                    print ("Bine ai venit %s" %(nume))
                print ("Lista cartilor noastre este: ")
                print (self._controller.getListaCarti())
                print ("Introduceti ID-ul cartii pe care doriti sa o imprumutati !")
                idCarte = input()
                self._controller.imprumutaCarte(int(idCarte),"Da", idPers)
                print ("Ati imprumutat cartea ! Lectura placuta")
            if n=="4":
                print ("Lista cartilor din baza de date: ")
                print (self._controller.getListaCarti())
            if n=="5":
                print ("Lista clientilor existenti in baza de date: ")
                print (self._controller.getListaPersoane())
            if n=="6":
                print ("Lista rapoartelor pe care le puteti vedea este: ")
                print ("1.Lista cu toate cartile imprumutate si valoarea lor totala.")
                print ("2.Lista cu toate cartile imprumutate si numar de imprumuturi pe carte.")  #NU VERIFICA SITUATIA DE IMPRUMUTATORI UNICI PE CARTE 
                print ("3.Lista imprumutatorilor in ordine descrescatoare a numarului de carti imprumutate.")
                print ("4.Lista autorilor, cei mai imprumutati, in ordine descrescatoare.")
                print ("5.Intoarcere la meniul principal.")
                while True:
                    m = input("Alegeti optiunea: ")
                    if m=="1":
                        print("Lista cartilor imprumutate:")
                        self._controller.listaCartiImprumutatePlusValoareTotala()
                    if m=="2":
                        print("Lista cartilor imprumutate plus numarul de imprumuturi:")
                        self._controller.listaCartiImprumutatePlusNrImprumuturi()
                    if m=="3":
                        print("Lista imprumutatorilor ordonati descrescator in functie de numarul de imprumuturi:")
                        self._controller.listaImprumutatoriOrd()
                    if m=="4":
                        print("Lista autorilor ordonati descrescator dupa numarul de imprumuturi: ")
                        self._controller.listaAutoriOrdDupaNrImprumuturi()
                    if m=="5":
                        break
            if n=="7":
                break

