from model.Carte import Carte
from model.Persoana import Persoana
from repository.RepositoryCarte import RepositoryCarte
from repository.RepositoryPersoana import RepositoryPersoana

class Controller():
    
    def __init__(self, repoCarte, repoPersoana):
        self._repoCarte = repoCarte
        self._repoPersoana = repoPersoana

    def addCarte(self, carte):
        self._repoCarte.addCarte(carte)

    def addPersoana(self,persoana):
        self._repoPersoana.addPersoana(persoana)

    def deleteCarte(self, idCarte):
        return self._repoCarte.deleteCarte(idCarte)

    def getListaCarti(self):
        return self._repoCarte.getListaCarti()

    def getListaPersoane(self):
        return self._repoPersoana.getListaPersoane()

    def imprumutaCarte(self, idCarte, statusImprumutata, idPers):
        if self._repoCarte.editCarte(idCarte, statusImprumutata) == "ok":
            self._repoPersoana.editPersoana(idPers, idCarte)
        else: 
            print("A aparut o erroare la imprumutarea cartii")

    def listaCartiImprumutatePlusValoareTotala(self):
        valoareTotala = 0
        for carte in self.getListaCarti():
            if carte.getImprumutata() == "Da":
                print ("Titlu carte: %s" % (carte.getTitlu()))
                valoareTotala += carte.getPret()
        print ("Valoarea totala a cartilor imprumutate este %d" % (valoareTotala))

    def listaCartiImprumutatePlusNrImprumuturi(self):
        for carte in self.getListaCarti():
            if carte.getImprumutata() == "Da":
                print ("Titlul carte: %s - Numar de imprumuturi: %d" % (carte.getTitlu(),carte.getNrImprumuturi()))
    
    def listaImprumutatoriOrd(self):
        listaPersoane = self.getListaPersoane()
        listaImprumutatori = {}
        for persoana in listaPersoane:
            listaImprumutatori[persoana.getNume()] = persoana.getNrCartiImprumutate() 
        for nume,nrCarti in sorted(listaImprumutatori.items(), key=lambda x: x[1], reverse=True):
            print("Nume: %s" %(nume) + "-" + "Numar carti imprumutate: %d" %(nrCarti))

    def listaAutoriOrdDupaNrImprumuturi(self):
        listaCarti = self.getListaCarti()
        listaAutori = {} # dictionar [numeaAutor] = aparitii / [key]=value
        for carte in listaCarti :
            if carte.getNumeAutor() not in listaAutori :
                listaAutori[carte.getNumeAutor()] = carte.getNrImprumuturi()
            else :
                listaAutori[carte.getNumeAutor()] = listaAutori.get(carte.getNumeAutor()) + carte.getNrImprumuturi()
        for autor,nrImprumuturi in sorted(listaAutori.items(), key=lambda x: x[1], reverse=True):  #pe baza valorii din x[1] care e valoare din dictionar returneaza un dictionar ordonat descrescator
            print ("Autor: %s" %(autor) + " - " + "Numar imprumuturi: %d" %(nrImprumuturi))
