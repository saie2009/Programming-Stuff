class Carte:

    def __init__(self,id , titlu, numeAutor, anulAparitiei, pret, editura, cota, numarInventar, imprumutata, nrImprumuturi):
        self._id=id
        self._titlu=titlu
        self._numeAutor=numeAutor
        self._anulAparitiei=anulAparitiei
        self._pret=pret
        self._editura=editura
        self._cota=cota
        self._numarInventar=numarInventar
        self._imprumutata=imprumutata
        self._nrImprumuturi=nrImprumuturi
    
    def __repr__(self):
        return "Carte #%d:\nTitlu: %s\nAutor: %s\nAnul aparitiei: %d\nPret: %d\nEditura: %s\nCota: %d\nNumar inventar: %d\nImprumutata: %s\nNumar imprumuturi: %d\n" % (self._id,self._titlu, self._numeAutor, self._anulAparitiei, self._pret, self._editura, self._cota, self._numarInventar, self._imprumutata, self._nrImprumuturi)

    def getId(self):
        return self._id

    def setId(self, id):
        self._id=id

    def getTitlu(self):
        return self._titlu

    def setTitlu(self, titlu):
        self._titlu=titlu

    def getNumeAutor(self):
        return self._numeAutor

    def setNumeAutor(self, numeAutor):
        self._numeAutor = numeAutor

    def getAnulAparitiei(self):
        return self._anulAparitiei

    def setAnulAparitiei(self, anulAparitiei):
        self._anulAparitiei = anulAparitiei

    def getPret(self):
        return self._pret
    
    def setPret(self, pret):
        self._pret = pret

    def getEditura(self):
        return self._editura

    def setEditura(self, editura):
        self._editura = editura

    def getCota(self):
        return self._cota

    def setCota(self, cota):
        self._cota = cota

    def getNumarInventar(self):
        return self._numarInventar

    def setNumarInventar(self, numarInventar):
        self._numarInventar = numarInventar
    
    def getImprumutata(self):
        return self._imprumutata

    def setImprumutata(self, imprumutata):
        self._imprumutata = imprumutata

    def getNrImprumuturi(self):
        return self._nrImprumuturi

    def setNrImprumuturi(self, nrImprumturi):
        self._nrImprumuturi = nrImprumturi
