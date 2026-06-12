# Repositorio individual de evidencia — Agente PETE

**Alumno:** Emilio Ceja Castillo 
**Proyecto:** Agente PETE  
**Materia:** Programación orientada a objetos  

## Descripción general

Este repositorio contiene mi evidencia individual del proyecto **Agente PETE**. El proyecto consiste en una aplicación que permite guardar un perfil de usuario, elegir un modelo preferido de IA y guardar el historial de conversaciones de manera local.

La solución fue diseñada usando programación orientada a objetos. Se identificaron los objetos principales del sistema, se definieron sus características y comportamientos, se elaboró un diagrama UML y se construyó una aplicación de prueba que usa las clases propuestas.

## Estructura del repositorio

```text
repositorio_evidencia_agente_pete/
│
├── 01_Presentacion_del_proyecto/
│   └── Presentacion_del_proyecto.md
│
├── 02_Planteamiento_del_problema/
│   └── Planteamiento_del_problema.md
│
├── 03_Diagrama_UML/
│   ├── Diagrama_UML.md
│   ├── diagrama_clases.puml
│   └── diagrama_clases.mmd
│
├── 04_Ejemplo_de_ejecucion/
│   ├── Ejemplo_de_ejecucion.md
│   └── Guion_para_video_demostrativo.md
│
├── 05_Argumentacion_POO/
│   └── Argumentacion_POO.md
│
├── 06_Conclusion_personal/
│   └── Conclusion_personal.md
│
└── codigo/
    ├── CMakeLists.txt
    ├── IDataStorage.h
    ├── UserProfile.h
    ├── UserProfile.cpp
    ├── PersistenceManager.h
    ├── PersistenceManager.cpp
    └── main.cpp
```

## Cumplimiento de especificaciones

| Especificación solicitada | Evidencia en el repositorio |
|---|---|
| Identificar objetos involucrados | `02_Planteamiento_del_problema/Planteamiento_del_problema.md` |
| Definir características y comportamientos | `02_Planteamiento_del_problema/Planteamiento_del_problema.md` |
| Diseñar modelo de clases | `03_Diagrama_UML/Diagrama_UML.md` |
| Usar herencia | `codigo/IDataStorage.h` y `codigo/PersistenceManager.h` |
| Usar polimorfismo | `codigo/main.cpp` usando apuntador `IDataStorage*` |
| Elaborar diagrama UML | `03_Diagrama_UML/diagrama_clases.puml` y `diagrama_clases.mmd` |
| Construir clases en lenguaje de programación | Carpeta `codigo/` |
| Crear aplicación que use las clases | `codigo/main.cpp` |
| Validar entradas del usuario | `codigo/main.cpp` y validaciones en `UserProfile.cpp` |
| Argumentar herencia, acceso, sobrecarga, sobreescritura, polimorfismo y clases abstractas | `05_Argumentacion_POO/Argumentacion_POO.md` |
| Conclusión personal | `06_Conclusion_personal/Conclusion_personal.md` |

## Nota importante

El archivo `PersistenceManager.cpp` original tenía una parte donde dos funciones `saveConversation` quedaron encimadas. En esta evidencia dejé el archivo corregido para que el diseño sea claro y pueda compilarse dentro de un proyecto Qt.
