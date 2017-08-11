import QtQuick 2.0

Rectangle {

    property int cote
    property bool vivante : false

    property int numLigne : -1
    property int numColonne : -1

    id : root
    width : cote
    height : cote

    border.width: 1
    border.color : "lightgrey"

    Rectangle{
        property real tailleCell : root.cote * 1/2.2

        visible : root.vivante

        width : tailleCell
        height : tailleCell
        anchors.centerIn: parent

        radius : width/2
        color :  "red"
    }
}
