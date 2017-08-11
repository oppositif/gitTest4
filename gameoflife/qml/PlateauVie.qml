import QtQuick 2.0

Rectangle {
    property int nbCellX : 24
    property int nbCellY : 20

    property int coteCell : 20
    id : root

    width : root.nbCellX * coteCell
    height : root.nbCellY * coteCell

    ListView{
        anchors.fill: parent
        orientation: ListView.Vertical
        interactive: false

        model : modelPlateau
        delegate : LigneCase {
            numLigne : index
            nbCell : nbCellX
            cote : root.coteCell
        }
        onModelChanged : {
            //console.log( "plateauModel = "+ model )
        }
    }
}
