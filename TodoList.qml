import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

import ToDo 1.0

 Frame {
//    width: 100
//    height: 200
     ListView {
         implicitWidth: 250;
         implicitHeight: 250;
         clip: true

         model: ToDoModel {}
//         model: ListModel {
//             ListElement {
//                 done: true
//                 description: "Hello John!"
//             }
//             ListElement {
//                 done: false
//                 description: "Good Bye!"
//             }
//         }

         delegate: RowLayout {
            width: parent.width
            CheckBox{
                checked: model.done;
                onClicked: model.done = checked;
            }
            TextField {
                text: model.description;
                onEditingFinished: model.description = text;
                Layout.fillWidth: true
            }
         }
     }

 }
