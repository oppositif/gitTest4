import QtQuick 2.0
import QtQuick.Controls 1.4

Rectangle{
    id: root
    property int largeurButton: 140
    Row{
        id: row
        spacing:10
        Rectangle{
            id: bandeau
            height: root.height
            width: 150
            visible: true
            color: "lightblue"


            Column{
                id: column
                spacing: 10
                Button{
                    text: "hide menu"
                    width: 80

                    onClicked:{
                        bandeau.visible = false
                        show.visible = true


                    }
                }
                Button{
                    text: "Reinitialiser"
                    width: root.largeurButton
                    onClicked : {
                        Context.sendActionToCpp("Reset", 'maChaineDuPlateau')
                    }
                }
                ComboBox{
                    id: combo
                    width: root.largeurButton
                    model:["1", "2", "5","10","20","50","100","200","500"]
                    onCurrentIndexChanged: Context.sendActionToCpp("Nombre", currentText)
                }
                TextField{
                    placeholderText: qsTr("Nombre d'iteration")
                    id: textfield
                    width: root.largeurButton
                    validator: RegExpValidator {
                                            regExp: /[0-9]+/
                    }
                    onEditingFinished : {
                        Context.sendActionToCpp("Nombre", textfield.text)
                        textfield.text =""
                    }
                }
                Button{
                    text: "Une iteration"
                    width: root.largeurButton
                    onClicked : {
                        Context.sendActionToCpp("Nombre", "1")
                    }
                }
                Button{
                    text: "Retour arrière"
                    width: root.largeurButton
                    onClicked : {
                        Context.sendActionToCpp("Reverse", 'maChaineDuPlateau')
                    }
                }
                Button{
                    text: "Sauvegarder"
                    width: root.largeurButton
                    onClicked : {
                        Context.sendActionToCpp("Sauvegarder", 'maChaineDuPlateau')
                    }
                }
                Button{
                    text: "Charger"
                    width: root.largeurButton
                    onClicked : {
                        Context.sendActionToCpp("Charger", 'maChaineDuPlateau')
                    }
                }
                Slider{
                    width: root.largeurButton
                    value: 0.5


                }

                Row{
                    spacing: 10
                    TextField{
                        placeholderText: qsTr("Taille X")
                        id: textfield2
                        width: root.largeurButton/2 -5
                        validator: RegExpValidator {
                                                regExp: /[0-9]+/
                        }
                        onEditingFinished : {
                            Context.sendActionToCpp("tailleX", text)
                            text =""
                        }
                    }
                    TextField{
                        placeholderText: qsTr("Taille Y")
                        id: textfield3
                        width: root.largeurButton/2 -5
                        validator: RegExpValidator {
                                                regExp: /[0-9]+/
                        }
                        onEditingFinished : {
                            Context.sendActionToCpp("TailleY", text)
                            text =""
                        }
                    }

                }
            }
        }
        Button{
            id: show
            width: 80
            text: "show menu"
            visible: false
            onClicked:{
                bandeau.visible = true
                show.visible = false
            }

        }

        PlateauVie {
            x : 120
            y : 20
            nbCellX : 24
            nbCellY : 20
            coteCell : 25
        }
    }
}
