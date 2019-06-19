import QtQuick 2.12
import QtQuick.Window 2.12
import don.geronimo 1.0
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainViewModel {
        id:viewModel
    }

    Frame {
        id: frame
        anchors.fill: parent

        ListView {
            id: listView
            x: 25
            y: 56
            width: 408
            height: 344
            model: viewModel.datas
            delegate: Item {
                x: 5
                width: 80
                height: 40
                Row {
                    id: row1
                    spacing: 10
                    Text {
                        text: id
                    }
                    Text {
                        text: value
                    }
                    Button{
                        text: "delete"
                        onClicked: {
                            viewModel.deleteData(id)
                        }
                    }
                }
            }
        }

        Button {
            id: button
            x: 88
            y: 0
            text: qsTr("Adicionar")
            onClicked: {
                viewModel.addData(edtId.text, edtValue.text)
            }
        }

        TextEdit {
            id: edtId
            x: 214
            y: 10
            width: 80
            height: 20
            font.pixelSize: 12
            property string placeholder: "Informe o id..."
            Text{
                text:edtId.placeholder
                color:"#aaa"
                visible: !edtId.text && !edtId.activeFocus
            }
        }

        TextEdit {
            id: edtValue
            x: 325
            y: 10
            width: 80
            height: 20
            font.pixelSize: 12
            property string placeholder: "informe o valor..."
            Text{
                text:edtValue.placeholder
                color:"#aaa"
                visible: !edtValue.text && !edtValue.activeFocus
            }
        }
    }
}
