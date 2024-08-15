
# AD-Interfaces

AD-Interfaces 是一个 C++ 库，提供了自动驾驶系统中常用的接口。

## 依赖

- OpenCV

## 安装

1. 安装 OpenCV:
   ```bash
   sudo apt-get install libopencv-dev
   ```

2. 克隆此仓库:
   ```bash
   git clone https://github.com/leoxiang66/AD-interfaces.git
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

1. 在你的项目的 CMakeLists.txt 文件中，添加以下内容:
   ```cmake
   set(ad_interfaces_DIR ~/include/lib/cmake/ad_interfaces)
   find_package(ad_interfaces REQUIRED)
   find_package(OpenCV REQUIRED)
   
   include_directories(~/include/include)
   include_directories(${OpenCV_INCLUDE_DIRS})
   ```

2. 将你的目标链接到 "ad_interfaces" 库和 OpenCV 库:
   ```cmake
   target_link_libraries(your_target ad_interfaces::perception ${OpenCV_LIBS})
   ```

   将 `your_target` 替换为你的实际目标名。

3. 为你的目标添加包含目录:
   ```cmake
   target_include_directories(your_target PRIVATE
     ~/include/include
     ~/include/include/perception
   )
   ```

4. 完整的 CMakeLists.txt 示例:
   ```cmake
   cmake_minimum_required(VERSION 3.10)
   project(my_project)

   # Set C++ standard
   set(CMAKE_CXX_STANDARD 11)
   set(CMAKE_CXX_STANDARD_REQUIRED True)

   # Find ad-interfaces package
   set(ad_interfaces_DIR ~/include/lib/cmake/ad_interfaces)
   find_package(ad_interfaces REQUIRED)

   find_package(OpenCV REQUIRED)
   
   include_directories(~/include/include)
   include_directories(${OpenCV_INCLUDE_DIRS})

   # Add executable
   add_executable(my_project src/main.cpp)

   # Link ad-interfaces library
   target_link_libraries(my_project ad_interfaces::perception ${OpenCV_LIBS})

   target_include_directories(my_project PRIVATE
     ~/include/include
     ~/include/include/perception
   )
   ```

5. 在你的 C++ 源文件中，引用所需的头文件:
   ```cpp
   #include <perception/CameraDetectorInterface.hpp>
   ```

   现在你可以使用 "ad-interfaces" 库提供的接口了。

## 故障排除

如果遇到 "No such file or directory" 错误，请尝试以下步骤：

1. 确保文件名和路径正确。例如，检查是否应该是 `CameraDetectorInterface.hpp` 而不是 `CameraDetectorInterface`。

2. 检查文件位置：
   ```bash
   find ~/include -name CameraDetectorInterface*
   ```

3. 检查文件权限：
   ```bash
   ls -l ~/include/include/perception/CameraDetectorInterface*
   ```

4. 如果使用 VSCode，更新 .vscode/c_cpp_properties.json 文件：
   ```json
   {
       "configurations": [
           {
               "name": "Linux",
               "includePath": [
                   "${workspaceFolder}/**",
                   "/opt/ros/humble/include/**",
                   "~/include/include/**",
                   "~/include/include/perception/**"
               ],
               // ... 其他设置 ...
           }
       ],
       "version": 4
   }
   ```

5. 如果问题仍然存在，可能需要重新安装 ad_interfaces 包。

## 注意事项

- 确保 `~/include` 路径存在并包含正确的文件和目录结构。
- 如果使用 `~` 不起作用，请使用完整的绝对路径（例如 `/home/yourusername/include`）。
- 在使用 ROS2 时，确保 ad_interfaces 包与你的 ROS2 版本兼容。

通过遵循这些步骤，你应该能够成功地在你的项目中使用 AD-Interfaces 库。如果仍然遇到问题，请查看错误信息并相应地调整路径或配置。
