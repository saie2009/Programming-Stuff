from model.Carte import Carte

class RepositoryCarte:
  
    def __init__(self, numeFisierCarti):
        self._listaCarti = []
        self.readCarte(numeFisierCarti)

    def addCarte(self, carte):
        """CREATE"""
        """Adaugare unei noi carti in lista"""
        self._listaCarti.append(carte)
    
    def readCarte(self,numeFisierCarti):
        """READ"""
        """Citirea datelor unei carti dintr-un fisier"""
        file = open(numeFisierCarti, "r") #deschidem fisierul
        for line in file:  #pentru fiecare linie
            data = line.split(",") # impartim datele in linie in functie de , 
            carte = Carte(int(data[0]),data[1],data[2],int(data[3]),int(data[4]),data[5],int(data[6]),int(data[7]),data[8],int(data[9])) #creem un obiect de tip Carte
            self.addCarte(carte) #adaugam cartea in lista
        file.close()

    def editCarte(self, idCarte, statusImprumutata):
        """UPDATE"""
        """Editarea datelor unei carti"""
        """Editare : statusImprumutata : da/nu"""
        """Cazul "Da" nrImprumuturi creste"""
        for carte in self.getListaCarti():
            if carte.getId() == idCarte:
                if statusImprumutata=="Da" and carte.getImprumutata() == "Da":
                    return "fail"
                if statusImprumutata=="Da":
                    carte.setImprumutata(statusImprumutata)
                    carte.setNrImprumuturi(carte.getNrImprumuturi()+1)
                    return "ok"
                if statusImprumutata=="Nu":
                    carte.setImprumutata(statusImprumutata)
                    return "ok"
        return "fail"

    def deleteCarte(self,idCarte):
        """DELETE"""
        """Sterge cartea din memorie cu id-ul dat"""
        for i in range(len(self._listaCarti)):
            carte = self._listaCarti[i]
            if carte.getId() == idCarte:
                del self._listaCarti[i]
                return "Cartea stearsa cu succes"
        return "Cartea nu a fost gasita !!!"

    def getListaCarti(self):
        """Obtinerea listei de carti"""
        return self._listaCarti
