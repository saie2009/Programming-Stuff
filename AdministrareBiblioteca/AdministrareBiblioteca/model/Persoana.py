class Persoana:

    def __init__(self, id, nume, idCarte, nrCartiImprumutate):
        self._id=id
        self._nume=nume
        self._idCarte=idCarte
        self._nrCartiImprumutate=nrCartiImprumutate

    def __repr__(self):
        return "Persoana #%d:\nNume: %s\nID Carte imprumutata: %d\nNumar carti imprumutate: %d\n" % (self._id,self._nume,self._idCarte,self._nrCartiImprumutate)
    def getId(self):
        return self._id

    def setId(self, id):
        self._id=id

    def getNume(self):
        return self._nume

    def setNume(self, nume):
        self._nume=nume

    def getIdCarte(self):
        return self._idCarte

    def setIdCarte(self, idCarte):
        self._idCarte=idCarte

    def getNrCartiImprumutate(self):
        return self._nrCartiImprumutate

    def setNrCartiImprumutate(self, nrCartiImprumutate):
        self._nrCartiImprumutate=nrCartiImprumutate

