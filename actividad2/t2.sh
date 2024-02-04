#!/bin/bash
user="rauljcastillo" && response=$(curl -s https://api.github.com/users/$user) && mkdir -p /tmp/$(date +"%d") && echo "Hola, $(echo $user). User ID: $(echo $response | jq -r .id). Cuenta creada el: $(date -d $(echo $response | jq -r .created_at) +"%d-%m-%Y")" >> /tmp/$(date +"%d"/hola.log)

#Colocar el comando crontab -e para ver el archivo de crontabs
#comando crontab: */5 * * * * /home/raul/Documentos/t2.sh

