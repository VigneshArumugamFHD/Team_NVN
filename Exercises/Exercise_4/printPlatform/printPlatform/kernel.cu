#include<stdio.h>
#include<CL/cl.h>



int main() 
{

            for (const cl::sycl::platform& platform : cl::sycl::platform::get_platforms()) 
            {

            std::cout << " ##Platform## " << std::endl;
            std::cout << " Name   : "
                << platform.get_info< cl::sycl::info::platform::name >() << std::endl;
            std::cout << " Vendor : "
                << platform.get_info< cl::sycl::info::platform::vendor >() << std::endl;
            std::cout << " Version: "
                << platform.get_info< cl::sycl::info::platform::version >() << std::endl;

     
            }

            return 0;
}