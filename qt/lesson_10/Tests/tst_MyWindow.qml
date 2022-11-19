import QtQuick 2.15
import QtTest 1.15
import QtQuick.Controls 2.15
import "../"

Item {
    width: 800
    height: 600
    MyWindow{
        id: testWin
    }
    TestCase {
        name: "Test ClearBut"
        when: windowShown
        function test_clickClearButton(){
            var test_name_z = findChild(testWin, "name_z")
            test_name_z.text = "aa"
            verify(testWin.test_task_name !== "", "Value empty")
            var test_button_clear = findChild(testWin, "m_but_clear")
            mouseClick(test_button_clear)
            verify(testWin.test_task_name === "", "Value not empty")
        }
        function test_clickClearButton2(){
            var test_name_z = findChild(testWin, "name_z")
            test_name_z.text = "aa"
            verify(testWin.test_task_name === "", "Value not empty")
        }
//        function test_clickClearButton(){
//            console.log("Value = " + testWin.test_task_name)
//            testWin.test_task_name = "sd"
//            console.log("Value = " + testWin.test_task_name)
//            verify(testWin.test_task_name !== "", "Value Empty")
//            testWin.test_clear_button.clicked()
//            console.log("Value = " + testWin.test_task_name)
//            verify(testWin.test_task_name === "", "Value not empty")
//        }

//      Почему нажатия кнопок не работают через проперти, а через findChild:
//      И как тут правильно тестировать GUI?
    }
}
