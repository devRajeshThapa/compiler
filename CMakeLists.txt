cmake_minimum_required(VERSION 3.28.3)

project(lyn LANGUAGES C CXX)

include_directories(include)

add_executable(lync src/lync.c src/error_handler.c src/lexer.c src/tokenizer.c)

install(TARGETS lync RUNTIME DESTINATION bin)
install(FILES docs/README_DIST.md DESTINATION docs RENAME README.md)
install(FILES LICENSE DESTINATION docs)
