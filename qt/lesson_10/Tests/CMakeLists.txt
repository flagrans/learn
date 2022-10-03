enable_testing()

# These commented out lines is the equivalense to the loop below.
#add_executable(Basics tst_basics.cpp)
#add_test(NAME Basics COMMAND Basics)
#target_link_libraries(Basics PRIVATE Qt6::Test)

# add_executable(Gadgets tst_gadgets.cpp)
# add_test(NAME Gadgets COMMAND Gadgets)
# target_link_libraries(Gadgets PRIVATE Qt5::Test QWAMLib)

function(SETUP_TESTS_CPP)
       foreach(_testname ${ARGN})
           add_executable(${_testname} tst_${_testname}.cpp )
           add_test(NAME ${_testname} COMMAND ${_testname})
           target_link_libraries(${_testname} Qt${QT_MAJOR_VERISION}::Test TestLibs)
       endforeach()
endfunction()

SETUP_TESTS_CPP(
   basics
)


add_definitions(-DQUICK_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
function(SETUP_TESTS_QML)
       foreach(_testname ${ARGN})
           add_executable(${_testname} testsQML.cpp tst_${_testname}.qml)
           add_test(NAME ${_testname} COMMAND ${_testname})
           target_link_libraries(${_testname} Qt${QT_MAJOR_VERISION}::QuickTest)
       endforeach()
endfunction()

SETUP_TESTS_QML(
   MyWindow
)

