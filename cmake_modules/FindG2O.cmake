# Find the header files
FIND_PATH(G2O_INCLUDE_DIR g2o/core/base_vertex.h
  ${G2O_ROOT}/include
  $ENV{G2O_ROOT}/include
  /usr/local/include
  /usr/include
  NO_DEFAULT_PATH
)

# Macro to find both Debug and Release versions of the libraries
MACRO(FIND_G2O_LIBRARY MYLIBRARY MYLIBRARYNAME)

  # 查找 Debug 版本库
  FIND_LIBRARY("${MYLIBRARY}_DEBUG"
    NAMES "libg2o_${MYLIBRARYNAME}_d"
    PATHS
    ${G2O_ROOT}/lib
    $ENV{G2O_ROOT}/lib
    /usr/local/g2o_debug/lib
    NO_DEFAULT_PATH
  )

  # 查找 Release 版本库（可以忽略，若无 Release 库）
  FIND_LIBRARY(${MYLIBRARY}
    NAMES "libg2o_${MYLIBRARYNAME}"
    PATHS
    ${G2O_ROOT}/lib
    $ENV{G2O_ROOT}/lib
    /usr/local/g2o_release/lib
    NO_DEFAULT_PATH
  )

  # 如果未找到 Release 版本库，将 Debug 版本路径赋值给 Release 变量
  IF(NOT ${MYLIBRARY})
    IF(${MYLIBRARY}_DEBUG)
      SET(${MYLIBRARY} ${${MYLIBRARY}_DEBUG})
    ENDIF()
  ENDIF()
  
ENDMACRO(FIND_G2O_LIBRARY)

# Find core components
FIND_G2O_LIBRARY(G2O_STUFF_LIBRARY stuff)
FIND_G2O_LIBRARY(G2O_CORE_LIBRARY core)
FIND_G2O_LIBRARY(G2O_CLI_LIBRARY cli)

# Find solver libraries
FIND_G2O_LIBRARY(G2O_SOLVER_CHOLMOD solver_cholmod)
FIND_G2O_LIBRARY(G2O_SOLVER_CSPARSE solver_csparse)
FIND_G2O_LIBRARY(G2O_CSPARSE_EXTENSION csparse_extension)
FIND_G2O_LIBRARY(G2O_SOLVER_DENSE solver_dense)
FIND_G2O_LIBRARY(G2O_SOLVER_PCG solver_pcg)
FIND_G2O_LIBRARY(G2O_SOLVER_SLAM2D_LINEAR solver_slam2d_linear)
FIND_G2O_LIBRARY(G2O_SOLVER_STRUCTURE_ONLY solver_structure_only)
FIND_G2O_LIBRARY(G2O_SOLVER_EIGEN solver_eigen)

# Find predefined types
FIND_G2O_LIBRARY(G2O_TYPES_DATA types_data)
FIND_G2O_LIBRARY(G2O_TYPES_ICP types_icp)
FIND_G2O_LIBRARY(G2O_TYPES_SBA types_sba)
FIND_G2O_LIBRARY(G2O_TYPES_SCLAM2D types_sclam2d)
FIND_G2O_LIBRARY(G2O_TYPES_SIM3 types_sim3)
FIND_G2O_LIBRARY(G2O_TYPES_SLAM2D types_slam2d)
FIND_G2O_LIBRARY(G2O_TYPES_SLAM3D types_slam3d)

# G2O solvers declared found if at least one solver is found
SET(G2O_SOLVERS_FOUND "NO")
IF(G2O_SOLVER_CHOLMOD OR G2O_SOLVER_CSPARSE OR G2O_SOLVER_DENSE OR G2O_SOLVER_PCG OR G2O_SOLVER_SLAM2D_LINEAR OR G2O_SOLVER_STRUCTURE_ONLY OR G2O_SOLVER_EIGEN)
  SET(G2O_SOLVERS_FOUND "YES")
ENDIF()

# G2O is declared found if core libraries and at least one solver are found
SET(G2O_FOUND "NO")
IF(G2O_STUFF_LIBRARY AND G2O_CORE_LIBRARY AND G2O_INCLUDE_DIR AND G2O_SOLVERS_FOUND)
  SET(G2O_FOUND "YES")
ENDIF()
