

Root=$(pwd)

LoaderTestDir=${Root}/build/main/Loader/test/Debug

cd ${LoaderTestDir}
./LoaderTest
cd ${Root}

SceneTestDir=${Root}/build/main/Scene/test/Debug

cd ${SceneTestDir}
./SceneTest
cd ${Root}
