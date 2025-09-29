target_sources(${PROJECT_NAME} PRIVATE 
  main.c
  ui.c
  player.c
  star.c
  planet.c
  planets.c
  missile.c
  missiles.c
  textures.c
  utils/logger.c
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
