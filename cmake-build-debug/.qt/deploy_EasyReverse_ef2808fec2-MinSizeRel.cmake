include("D:/Code/cpp/Repos/EasyReverse/cmake-build-debug/.qt/QtDeploySupport-MinSizeRel.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/EasyReverse-plugins-MinSizeRel.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/Code/cpp/Repos/EasyReverse/cmake-build-debug/MinSizeRel/EasyReverse.exe
    GENERATE_QT_CONF
)
