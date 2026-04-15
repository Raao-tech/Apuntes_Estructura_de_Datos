#!/bin/bash
# Descripción: Este script permite crear un los archivos .c/.h necesarios
#              para la creación de un TAD de forma automática.
# Autor: Rafael Araujo
# Fecha: 15-04-2025

read -p "¿Cómo se llamará el nuevo TAD? >" name_tad;
echo -e "¿En que directorio?\033[1;35m";

ls -d */ 2>/dev/null

echo -e "\033[0m";

read -p "¿Directorio? >>>" dir;

[ ! -d ${dir} ] && mkdir  ./${dir}/
if [[ -f "./${dir}/${name_tad}.h"   ||  -f "./${dir}/${name_tad}.c" ]]; then
    echo -e "Disculpa, pero ya existe un tad con esa ubicación y nombre\n"
    exit 1;
fi

touch  ./${dir}/${name_tad}.h
touch  ./${dir}/${name_tad}.c

echo -e "/** \n *   @file   ${name_tad}.h\n *   @brief  Cabecera de la estructura ${name_tad}\n *   @author Rafael Araujo\n *   @date   $(date +"%d-%m-%Y")\n */\n" > "./${dir}/${name_tad}.h"
echo -e "#ifndef ${name_tad^^}_H\n#define ${name_tad^^}_H\n\n//Tu código aquí\n\n#endif" >> "./${dir}/${name_tad}.h"
echo -e "/** \n *   @file   ${name_tad}.c\n *   @brief  Implementación de la estructura ${name_tad}\n *   @author Rafael Araujo\n *   @date   $(date +"%d-%m-%Y")\n */\n" > "./${dir}/${name_tad}.c"
echo -e "#include <stdio.h>\n#include \"../types.h\"\n#include \"${name_tad}.h\"\n" >> "./${dir}/${name_tad}.c"

echo -e "Todo listo ;D\n"