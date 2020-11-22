cmake_minimum_required(VERSION 3.19)
project(Hello_World VERSION 1.0)

add_subdirectory(say_hello)
add_subdirectory(hello-exe)
add_subdirectory(test)

enable_testing()
add_test(NAME MyTest COMMAND Test)

set(SHOW_NAME "This is cool")
set(GET_NAME "This is cool")
set(NUM 1)

if((SHOW_NAME STREQUAL GET_NAME) AND ("1" EQUAL NUM))
    set(MY_NAME "Girts")
    message(STATUS "YO ${MY_NAME}, this is ${PROJECT_NAME}")
elseif(GET_NAME EQUAL "cool$")
    message(STATUS "The word cool was found")
else()
    message(STATUS "Failed condition")
endif()

while(NUM LESS 50)
    message(STATUS "The number is ${NUM}")
    math(EXPR NUM "${NUM} + 1")
endwhile()

foreach(item IN ITEMS num1 num2 num3 num4)
    message(STATUS "Item is: ${item}")
endforeach()

foreach(id RANGE 10)
    message(STATUS "Index is: ${id}")
endforeach()

set(num_list 1 2 3)
set(target DIRECTORY "${PROJECT_SOURCE_DIR}")
set_property(
    ${target}
    PROPERTY Number
    "${num_list}"
)

# Gets the variables from global scope
# get_cmake_property(Num_value Number)
get_property(Num_value ${target} PROPERTY Number)
message(STATUS "Value of Number is ${Num_value}")

function(do_something num1)
    message(STATUS "You called a function with number: ${num1}")
endfunction()

do_something(1)

# Functions have default argument values as lists
function(print_arguments num1 num2 num3)
    # ARGN unbound arguments
    foreach(argument IN LISTS ARGN)
        message(STATUS "The passed ARGN argument is: ${argument}")
    endforeach()

    # ARGV all arguments
    foreach(argument IN LISTS ARGV)
        message(STATUS "The passed ARGV argument is: ${argument}")
    endforeach()
endfunction()

print_arguments(1 2 3 4 5 6)

set(GLOBAL_VAR Cool)

function(see_scope)
    message(STATUS "Global var is: ${GLOBAL_VAR}")
    # The only easy way to return a value to the caller
    set(GLOBAL_VAR 10 PARENT_SCOPE)
    message(STATUS "Global var is: ${GLOBAL_VAR}")
endfunction()

set(GLOBAL_VAR Cool)

see_scope()

message(STATUS "Global var is: ${GLOBAL_VAR}")

function(increment var)
    math(EXPR new_var "${${var}} + 1")
    set("${var}" "${new_var}" PARENT_SCOPE)
endfunction()

set(value 10)
message(STATUS "Value before increment is ${value}")
increment(value)
increment(value)
increment(value)
increment(value)
message(STATUS "Value after increment is ${value}")

function(sum out a b)
    math(EXPR result "${a} + ${b}")
    set("${out}" "${result}" PARENT_SCOPE)    
endfunction()

set(sum_result)
sum(sum_result 1 2)
message(STATUS "The sum result is: ${sum_result}")