# CMake generated Testfile for 
# Source directory: /home/joao/Documents/UA/IC/Aula03/opencv-master/modules/flann
# Build directory: /home/joao/Documents/UA/IC/Aula03/build/modules/flann
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_flann "/home/joao/Documents/UA/IC/Aula03/build/bin/opencv_test_flann" "--gtest_output=xml:opencv_test_flann.xml")
set_tests_properties(opencv_test_flann PROPERTIES  LABELS "Main;opencv_flann;Accuracy" WORKING_DIRECTORY "/home/joao/Documents/UA/IC/Aula03/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/joao/Documents/UA/IC/Aula03/opencv-master/cmake/OpenCVUtils.cmake;1738;add_test;/home/joao/Documents/UA/IC/Aula03/opencv-master/cmake/OpenCVModule.cmake;1352;ocv_add_test_from_target;/home/joao/Documents/UA/IC/Aula03/opencv-master/cmake/OpenCVModule.cmake;1110;ocv_add_accuracy_tests;/home/joao/Documents/UA/IC/Aula03/opencv-master/modules/flann/CMakeLists.txt;2;ocv_define_module;/home/joao/Documents/UA/IC/Aula03/opencv-master/modules/flann/CMakeLists.txt;0;")
