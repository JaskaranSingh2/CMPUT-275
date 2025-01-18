#!/bin/bash



changeExtension() {
  for fileName in  *${1}; do
    if [ ${fileName} != "*${1}" ]; then
      fileStem="${fileName%${1}}"
      mv ${fileStem}${1} ${fileStem}${2}
    fi
  done
}

changeExtension .cpp .cc
changeExtension .hpp .h
