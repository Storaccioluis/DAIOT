# DAIoT 2022

## Conexión del ESP32 a Google Cloud IoT-Core

Configurar SSID y PASSWORD de la red Wi-Fi en el archivo smart_config.c

Configurar tu ID de dispositivo segun tu nombre, en el archivo mqtt_basico.h

El certificado incluido en el archivo pemhey.h fue generado en la consola de Google Cloud.
Se utilizo el siguiente comando:

openssl req -x509 -nodes -newkey rsa:2048 -keyout rsa_lz_private.pem -out rsa_lz_cert.pem -subj "/CN=unused" -days 36500 


Descargar de GCP el certificado CA mínimo y convertirlo a formato PEM con OPENSSL:
 * https://cloud.google.com/iot/docs/how-tos/mqtt-bridge#using_a_long-term_mqtt_domain
 * Cert primario: https://pki.goog/gtsltsr/gtsltsr.crt
 * Cert backup: https://pki.goog/gsr4/GSR4.crt
 
openssl x509 -inform DER -in gtsltsr.crt -out primary.pem -text
Copiar el fragmento desde BEGIN a END dentro del archivo "gcp_min_ca.h"