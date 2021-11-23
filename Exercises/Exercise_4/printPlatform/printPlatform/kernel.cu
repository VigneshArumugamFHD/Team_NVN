#include <stdio.h>
#include <stdlib.h>
#include <OpenCL/cl.h>



int main() {

    int i, j;
    char* info;
    size_t infoSize;
    cl_uint platformCount;
    cl_platform_id* platforms;


    const char* attributeNames[5] = { "Name", "Vendor", "Version", "Profile", "Extensions" };

    const cl_platform_info attributeTypes[5] = { CL_PLATFORM_NAME, CL_PLATFORM_VENDOR, CL_PLATFORM_VERSION, CL_PLATFORM_PROFILE, CL_PLATFORM_EXTENSIONS };
    const int attributeCount = sizeof(attributeNames) / sizeof(char*);

    clGetPlatformIDs(5, NULL, &platformCount);

    platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id) * platformCount);
    clGetPlatformIDs(platformCount, platforms, NULL);


    for (i = 0; i < platformCount; i++) {

        for (j = 0; j < attributeCount; j++) {

            clGetPlatformInfo(platforms[i], attributeTypes[j], 0, NULL, &infoSize);
            info = (char*)malloc(infoSize);

            clGetPlatformInfo(platforms[i], attributeTypes[j], infoSize, info, NULL);

            printf("%s: %s\n", i + 1, j + 1, attributeNames[j], info);

            free(info);

        }

        printf("\n");

    }

    free(platforms);

    return 0;

}