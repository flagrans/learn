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
            console.log("Value = " + testWin.test_task_name)
            testWin.test_task_name = "sd"
            console.log("Value = " + testWin.test_task_name)
            verify(testWin.test_task_name !== "", "Value Empty")
            testWin.test_clear_button.clicked()
            console.log("Value = " + testWin.test_task_name)
            verify(testWin.test_task_name === "", "Value not empty")
        }
    }
}
