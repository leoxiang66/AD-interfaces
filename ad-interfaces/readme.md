
# AD-Interfaces

AD-Interfaces 是一个 C++ 库,提供了自动驾驶系统中常用的接口。

## 依赖

- OpenCV

## 安装

1. 安装 OpenCV:
   ```bash
   sudo apt-get install libopencv-dev
   ```

2. 克隆此仓库:
   ```bash
   git clone https://github.com/yourusername/ad-interfaces.git
   ```

3. 进入 "ad-interfaces" 目录:
   ```bash
   cd ad-interfaces
   ```

4. 运行 `make` 命令安装库:
   ```bash
   make install
   ```

   这会将 "ad-interfaces" 库安装到 `~/include` 目录。

## 使用

要在你的 C++ 项目中使用 "ad-interfaces" 库:

1. 在你的项目的 CMakeLists.txt 文件中,添加以下内容:
   ```cmake
   set(ad_interfaces_DIR ~/include/lib/cmake/ad_interfaces)
   find_package(ad_interfaces REQUIRED)
   find_package(OpenCV REQUIRED)
   include_directories(${OpenCV_INCLUDE_DIRS})
   ```

   这会告诉 CMake 在 `~/include/lib/cmake/ad_interfaces` 目录中查找 "ad-interfaces" 库的配置文件,并找到 OpenCV 库。

2. 将你的目标链接到 "ad_interfaces" 库和 OpenCV 库:
   ```cmake
   target_link_libraries(your_target ad_interfaces::perception ${OpenCV_LIBS})
   ```

   将 `your_target` 替换为你的实际目标名。

   example CMakeLists.txt:
    ```
    cmake_minimum_required(VERSION 3.10)
    project(my_project)

    # Set C++ standard
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_STANDARD_REQUIRED True)



    # Find ad-interfaces package
    set(ad_interfaces_DIR ~/include/lib/cmake/ad_interfaces)
    find_package(ad_interfaces REQUIRED)

    find_package(OpenCV REQUIRED)
    include_directories(${OpenCV_INCLUDE_DIRS})

    # Add executable
    add_executable(my_project src/main.cpp)

    # Link ad-interfaces library
    target_link_libraries(my_project ad_interfaces::perception ${OpenCV_LIBS})
    ```

3. 在你的 C++ 源文件中,引用所需的头文件:
   ```cpp
   #include <perception/PerceptionInterface.hpp>
   ```

   现在你可以使用 "ad-interfaces" 库提供的接口了。

