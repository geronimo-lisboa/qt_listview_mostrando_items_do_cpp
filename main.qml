import QtQuick 2.12
import QtQuick.Window 2.12
import don.geronimo 1.0
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.0
import QtQuick.Layouts 1.0


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    Material.theme: Material.Dark
    title: qsTr("Hello World")

    MainViewModel {
        id:viewModel
    }

    Frame {
        id: frame
        anchors.fill: parent

        ColumnLayout {
            x: 25
            y: 0

            RowLayout {
                TextEdit {
                    id: edtId
                    Layout.preferredHeight: 20
                    Layout.preferredWidth: 80
                    font.pixelSize: 12
                    property string placeholder: "Informe o id..."
                    Layout.fillWidth: true
                    Text{
                        text:edtId.placeholder
                        color:"#aaa"
                        visible: !edtId.text && !edtId.activeFocus
                    }
                }

                TextEdit {
                    id: edtValue
                    Layout.preferredHeight: 20
                    Layout.preferredWidth: 80
                    font.pixelSize: 12
                    property string placeholder: "informe o valor..."
                    Layout.fillWidth: true
                    Text{
                        text:edtValue.placeholder
                        color:"#aaa"
                        visible: !edtValue.text && !edtValue.activeFocus
                    }
                }

                Button {
                    id: button
                    Layout.maximumHeight: 40
                    Layout.minimumHeight: 40
                    Layout.preferredHeight: 40
                    Layout.maximumWidth: 40
                    Layout.minimumWidth: 40
                    Layout.preferredWidth: 40
                    icon.source: "round_add_black_18dp.png"
                    onClicked: {
                        viewModel.addData(edtId.text, edtValue.text)
                    }
                }
            }

            ListView {
                id: listView
                Layout.preferredHeight: 344
                Layout.preferredWidth: 408
                model: viewModel.datas
                delegate: Pane {
                    width: parent.width
                    Material.elevation: 8
                    RowLayout {
                        spacing: 10
                        width: parent.width
                        Text {
                            text: id
                            font.pixelSize: 12
                            Layout.fillWidth: true

                        }
                        Text {
                            text: value
                            font.pixelSize: 12
                            Layout.fillWidth: true
                        }
                        Button{
                            icon.source: "round_clear_black_18dp.png"
                            onClicked: {
                                viewModel.deleteData(id)
                            }
                        }
                    }

                }
            }
        }
    }
}
