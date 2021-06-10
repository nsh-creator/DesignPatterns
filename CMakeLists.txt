cmake_minimum_required(VERSION 3.5)

Project(DesignPatterns)

Set(PATTERNS
    factory
)

foreach(pattern IN ITEMS ${PATTERNS})

    file(GLOB SIR_LIST "${pattern}/*.cpp")
    
    foreach(_file IN ITEMS ${SIR_LIST})
        get_filename_component(_file_name
                                    ${_file} NAME
            )
        set(_project_name "${_file_name}")
        add_executable(${_project_name} "${pattern}/${_file_name}")
    endforeach()
endforeach()
