# Create a shared library called "PROGRESS" which includes the source file "progress.c".
# The extension is already found. Any number of sources could be listed here.
add_library(Progress SHARED progress.c)
# header
set_target_properties(Progress PROPERTIES PUBLIC_HEADER progress.h)


# shared lib search /lib /usr/lib
install(TARGETS Progress
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # --prefix "/usr" /usr/lib
        PUBLIC_HEADER DESTINATION local/${CMAKE_INSTALL_INCLUDEDIR}) # --prefix "/usr" /usr/local/include

# Make sure the compiler can find include files for our PROGRESS library
# when other libraries or executables link to Hello
target_include_directories(Progress PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})