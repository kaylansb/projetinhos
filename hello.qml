import QtQuick
import QtQuick.Layouts
import QtQuick.Controls.Material


ApplicationWindow {
    id: window
    width: 640
    height: 480
    minimumWidth: 200
    minimumHeight: 250
    visible: true
    title: qsTr("Hello World")

    ColumnLayout {
        anchors {
            fill: parent
            margins: 20
        }

        Label {
            text: "WELCOME"
            Layout.alignment: Qt.AlignHCenter
            font.pixelSize: 48
        }

        Frame {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Material.elevation: 10

            ColumnLayout {
                width: parent.width
                anchors.verticalCenter: parent.verticalCenter
                spacing: 15

                TextField {
                    id: usernameTextField

                    Layout.fillWidth: true
                    placeholderText: "username"
                }
                TextField {
                    id: passwordTextField

                    Layout.fillWidth: true
                    placeholderText: "password"
                    echoMode: TextInput.Password

                    SequentialAnimation on scale {
                        id: errorAnimation

                        running: false
                        loops: 5


                        NumberAnimation {from: 1; to: 0.98; duration: 20}
                        NumberAnimation {from: 0.98; to: 1; duration: 20}
                    }
                }
                Label {
                    id: errorLabel

                    color: "red"
                    Layout.alignment: Qt.AlignHCenter
                }
                Button {
                    text: "Sign In"
                    highlighted: true
                    Layout.alignment: Qt.AlignHCenter
                    onClicked: {
                        if (usernameTextField.text !== 'user' || passwordTextField.text !== 'password'){
                            errorLabel.text = 'Sign in error!'
                            errorAnimation.start()
                        }
                    }
                }
            }
        }
    }
}
