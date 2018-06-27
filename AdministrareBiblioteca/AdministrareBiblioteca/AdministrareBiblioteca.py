from repository.RepositoryCarte import RepositoryCarte
from repository.RepositoryPersoana import RepositoryPersoana
from controller.Controller import Controller
from ui.UI import UI

repoCarte=RepositoryCarte("carti.txt")
repoPersoana=RepositoryPersoana("persoane.txt")
ctr=Controller(repoCarte,repoPersoana)
ui=UI(ctr)
ui.run()


