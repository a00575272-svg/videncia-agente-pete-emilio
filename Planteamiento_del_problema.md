# Planteamiento del problema

## Situación problema

Se necesita crear una aplicación llamada **Agente PETE** que pueda guardar información básica de un usuario y también registrar sus conversaciones. El sistema debe permitir que los datos no se pierdan al cerrar el programa, por eso se usa almacenamiento en archivos JSON.

El problema se puede resolver con programación orientada a objetos porque hay varios elementos que tienen datos y acciones propias. Por ejemplo, el usuario tiene un nombre y un modelo preferido, mientras que el administrador de persistencia se encarga de guardar y cargar la información.

## Objetos involucrados

### 1. Usuario / Perfil de usuario

**Clase:** `UserProfile`

**Características:**

- Nombre del usuario.
- Modelo de IA preferido.

**Comportamientos:**

- Obtener el nombre del usuario.
- Cambiar el nombre del usuario.
- Obtener el modelo preferido.
- Cambiar el modelo preferido.
- Convertir el perfil a JSON.
- Crear un perfil desde un archivo JSON.

Esta clase representa los datos principales del usuario. Ayuda a que la aplicación pueda guardar y recuperar la configuración personal.

### 2. Almacenamiento de datos

**Clase abstracta:** `IDataStorage`

**Características:**

- No guarda datos directamente.
- Define las operaciones que cualquier clase de almacenamiento debe tener.

**Comportamientos:**

- Inicializar el sistema de almacenamiento.
- Guardar perfil del usuario.
- Cargar perfil del usuario.
- Guardar conversación.
- Cargar historial.

Esta clase funciona como una base o contrato. Sirve para indicar qué métodos debe tener cualquier clase que quiera guardar información.

### 3. Administrador de persistencia

**Clase:** `PersistenceManager`

**Características:**

- Ruta de la carpeta donde se guardan los datos.
- Ruta del archivo del perfil.
- Ruta del archivo del historial.

**Comportamientos:**

- Crear la carpeta de datos si no existe.
- Crear el archivo de historial si no existe.
- Guardar el perfil del usuario en JSON.
- Cargar el perfil del usuario desde JSON.
- Guardar conversaciones.
- Cargar el historial de conversaciones.

Esta clase se encarga de la parte de almacenamiento real. Usa archivos JSON para que los datos se conserven aunque el programa se cierre.

### 4. Aplicación principal

**Archivo:** `main.cpp`

**Características:**

- Menú de opciones.
- Entrada de datos del usuario.
- Objeto de almacenamiento.

**Comportamientos:**

- Mostrar opciones al usuario.
- Validar entradas.
- Crear y guardar el perfil.
- Registrar conversaciones.
- Mostrar historial.
- Usar las clases del sistema.

La aplicación principal sirve para probar que las clases funcionan correctamente y que sí resuelven la situación problema.

## Solución propuesta

La solución consiste en separar el programa en clases. La clase `UserProfile` maneja los datos del usuario. La clase abstracta `IDataStorage` define cómo debe comportarse cualquier almacenamiento. La clase `PersistenceManager` hereda de `IDataStorage` y realiza el almacenamiento real en archivos.

Con este diseño, el sistema queda más ordenado porque cada clase tiene una responsabilidad clara. Además, se puede cambiar la forma de guardar los datos en el futuro sin afectar demasiado al resto del programa.

## Validación de entradas

El sistema valida las entradas del usuario para evitar errores. Por ejemplo:

- El nombre no puede estar vacío.
- El modelo debe elegirse de una lista válida.
- El prompt o pregunta no puede estar vacío.
- El menú solo acepta números dentro del rango permitido.

Esto ayuda a que el programa funcione correctamente y evita que se guarden datos incompletos.
