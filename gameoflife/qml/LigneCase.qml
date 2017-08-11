import QtQuick 2.0

ListView {
    property int cote
    property int nbCell

    property int numLigne // l'index de la ligne dans le PlateauVie

    property string ligneCase_model : modelData

    onLigneCase_modelChanged: {
        // Transformation de la chaîne de caractère en tableau
        // Pour pouvoir affecter dynamiquement ce tableau au model de LigneCase

        var rsltModel = []
        for( var i=0 ; i< ligneCase_model.length ; i++)
        {
            rsltModel.push(ligneCase_model[i])
        }
        root.model = rsltModel
    }

    id : root

    width : cote*nbCell
    height : root.cote

    orientation: ListView.Horizontal
    interactive: false

//    model : le model n'est pas instancié au départ, mais à la création des éléments parents
    delegate : Case {
        cote : root.cote
        vivante : modelData=="1"       

        numColonne: index
        numLigne: root.numLigne

        MouseArea{
            anchors.fill : parent
            onClicked : {
                console.log(numColonne +' ' +root.numLigne )
                Context.sendCaseToCpp(Qt.point(numColonne, numLigne))
            }
        }
    }
}
