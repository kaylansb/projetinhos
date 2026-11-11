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


// }

// ApplicationWindow {
//     id: root
//     width: 300
//     height: 300
//     visible: true

    // RowLayout {
    //     anchors.fill: parent
    //     ColumnLayout {
    //         // spacing: 0
    //         Rectangle {
    //             color: "tomato";
    //             Layout.fillWidth: true
    //             Layout.fillHeight: true
    //         }
    //         RowLayout {
    //             spacing: 0
    //             Rectangle {
    //                 color: "navajowhite"
    //                 Layout.fillWidth: true
    //                 Layout.fillHeight: true
    //             }
    //             Rectangle {
    //                 color: "darkseagreen"
    //                 Layout.fillWidth: true
    //                 Layout.fillHeight: true
    //             }
    //         }
    //     }
    //     ColumnLayout {
    //         // spacing: 0
    //         Rectangle {
    //             color: "lightpink"
    //             Layout.fillWidth: true
    //             Layout.fillHeight: true
    //         }
    //         Rectangle {
    //             color: "slategray"
    //             Layout.fillWidth: true
    //             Layout.fillHeight: true
    //         }
    //         Rectangle {
    //             color: "lightskyblue"
    //             Layout.fillWidth: true
    //             Layout.fillHeight: true
    //         }
    //     }
    //     ColumnLayout {
    //         // spacing: 0
    //         Rectangle {
    //             color: "lightpink"
    //             Layout.fillWidth: true
    //             Layout.fillHeight: true
    //         }
    //         Rectangle {
    //             color: "slategray"
    //             Layout.fillWidth: true
    //             Layout.fillHeight: true
    //         }
    //         Rectangle {
    //             color: "lightskyblue"
    //             Layout.fillWidth: true
    //             Layout.fillHeight: true
    //         }
    //     }
    // }


//     ColumnLayout {
//         anchors.fill: parent
//         spacing: 0
//         RowLayout {
//             spacing: 0
//             Rectangle {
//                 color: "lightskyblue"
//                 Layout.fillWidth: true
//                 Layout.fillHeight: true
//             }
//             Rectangle {
//                 color: "yellow"
//                 Layout.fillWidth: true
//                 Layout.fillHeight: true
//             }
//             Rectangle {
//                 color: "brown"
//                 Layout.fillWidth: true
//                 Layout.fillHeight: true
//             }
//         }

//         RowLayout {
//             spacing: 0
//             Rectangle {
//                 color: "black"
//                 Layout.fillWidth: true
//                 Layout.fillHeight: true
//             }
//             Rectangle {
//                 color: "gray"
//                 Layout.fillWidth: true
//                 Layout.fillHeight: true
//             }
//         }
//     }



    ColumnLayout {
        anchors.fill: parent
        RowLayout {
            Layout.fillWidth: true
            Layout.fillHeight: false

            Button {
                text: "teste"
            }

            Label {
                text: "PARINTINS"
                font.pixelSize: 40
                Layout.alignment: Qt.AlignVCenter
            }
        }

        Rectangle {
            color: "red"
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        Rectangle {
            color: "blue"
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }

}
