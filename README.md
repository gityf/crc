# crc
  crc16/crc32/crc64

## Build

``` bash
git clone https://github.com/gityf/crc.git
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS=1
make 
```

## Include 

### Cmake build system 

``` cmake
add_subdirectory(crc)

target_link_libraries(${PROJECT_NAME} PUBLIC crc)

```
