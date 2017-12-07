set(CPACK_PACKAGE_VENDOR "Lysergic")
set(CPACK_PACKAGE_CONTACT "Alessandro Siniscalchi <asiniscalchi@gmail.com>")

if(WIN32 AND NOT UNIX)
else()
    set(CPACK_GENERATOR "DEB;TGZ")
endif()

include(CPack)
