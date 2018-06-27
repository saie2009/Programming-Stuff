from model.Persoana import Persoana

class RepositoryPersoana():
    
    def __init__(self,numeFisierPersoane):
        self._listaPersoane = []
        self.readPersoane(numeFisierPersoane)

    def addPersoana(self, persoana):
        self._listaPersoane.append(persoana)

    def editPersoana(self,idPers, idCarte):
        for persoana in self.getListaPersoane():
            if persoana.getId() == idPers:
                persoana.setIdCarte(idCarte)
                persoana.setNrCartiImprumutate(persoana.getNrCartiImprumutate()+1)

    def readPersoane(self, numeFisierPersoane):
        """READ"""
        """Citirea datelor unei persoane dintr-un fisier"""
        file = open(numeFisierPersoane, "r") #deschidem fisierul
        for line in file:  #pentru fiecare linie
            data = line.split(",") # impartim datele in linie in functie de , 
            persoana = Persoana(int(data[0]),data[1],int(data[2]),int(data[3])) #creem un obiect de tip Persoana
            self.addPersoana(persoana) #adaugam persoana in lista
        file.close()


    def getListaPersoane(self):
        return self._listaPersoane


