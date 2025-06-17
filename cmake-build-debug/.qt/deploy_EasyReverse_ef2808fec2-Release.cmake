include("D:/Code/cpp/Repos/EasyReverse/cmake-build-debug/.qt/QtDeploySupport-Release.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/EasyReverse-plugins-Release.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/Code/cpp/Repos/EasyReverse/cmake-build-debug/Release/EasyReverse.exe
    GENERATE_QT_CONF
)
