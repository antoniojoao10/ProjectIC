# CMake generated Testfile for 
# Source directory: /home/joao/Documents/UA/IC/Aula03/opencv-master/modules/highgui
# Build directory: /home/joao/Documents/UA/IC/Aula03/build/modules/highgui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_highgui "/home/joao/Documents/UA/IC/Aula03/build/bin/opencv_test_highgui" "--gtest_output=xml:opencv_test_highgui.xml")
set_tests_properties(opencv_test_highgui PROPERTIES  LABELS "Main;opencv_highgui;Accuracy" WORKING_DIRECTORY "/home/joao/Documents/UA/IC/Aula03/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/joao/Documents/UA/IC/Aula03/opencv-master/cmake/OpenCVUtils.cmake;1738;add_test;/home/joao/Documents/UA/IC/Aula03/opencv-master/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/joao/Documents/UA/IC/Aula03/opencv-master/modules/highgui/CMakeLists.txt;280;ocv_add_accuracy_tests;/home/joao/Documents/UA/IC/Aula03/opencv-master/modules/highgui/CMakeLists.txt;0;")
