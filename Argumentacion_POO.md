# Argumentación de conceptos de programación orientada a objetos

## Herencia

La herencia se aplica porque la clase `PersistenceManager` hereda de la clase abstracta `IDataStorage`.

Esto significa que `PersistenceManager` toma como base las operaciones definidas en `IDataStorage` y las implementa de manera concreta. En este caso, `PersistenceManager` sí sabe cómo guardar y cargar datos usando archivos JSON.

Ejemplo:

```cpp
class PersistenceManager : public IDataStorage
```

## Clase abstracta

`IDataStorage` es una clase abstracta porque tiene métodos virtuales puros. Esta clase no se usa para crear objetos directamente. Su función es definir qué métodos debe tener cualquier clase de almacenamiento.

Ejemplo:

```cpp
virtual bool initialize() = 0;
virtual bool saveConversation(const QString &prompt,
                              const QString &response) = 0;
```

Esto ayuda a que el sistema sea más flexible, porque en el futuro se podría crear otro tipo de almacenamiento, por ejemplo `DatabaseStorage`, y también podría heredar de `IDataStorage`.

## Polimorfismo

El polimorfismo se aplica cuando el programa usa un apuntador de tipo `IDataStorage*`, pero el objeto real es de tipo `PersistenceManager`.

Ejemplo:

```cpp
PersistenceManager manager;
IDataStorage *storage = &manager;
storage->initialize();
```

Esto funciona porque `PersistenceManager` implementa los métodos de `IDataStorage`. El programa no necesita saber exactamente qué tipo de almacenamiento está usando, solo necesita saber que cumple con el contrato de `IDataStorage`.

## Sobreescritura de métodos

La sobreescritura se usa cuando `PersistenceManager` implementa métodos que fueron definidos en `IDataStorage`.

Ejemplo:

```cpp
bool initialize() override;
bool saveConversation(const QString &prompt,
                      const QString &response) override;
```

La palabra `override` indica que el método está reemplazando la versión definida en la clase base.

## Sobrecarga de métodos

La sobrecarga se aplica con el método `saveConversation`, porque existen dos versiones con el mismo nombre, pero con diferentes parámetros.

Ejemplo:

```cpp
bool saveConversation(const QString &prompt,
                      const QString &response);

bool saveConversation(const QString &prompt);
```

La primera versión guarda una pregunta y una respuesta. La segunda versión guarda solo la pregunta y coloca automáticamente una respuesta como `[Sin respuesta]`.

## Modificadores de acceso

El proyecto usa modificadores de acceso para proteger los datos.

### `private`

Los atributos de `UserProfile` son privados:

```cpp
private:
    QString userName;
    QString preferredModel;
```

Esto evita que otras partes del programa modifiquen los datos directamente.

### `public`

Los métodos públicos permiten interactuar con la clase de forma controlada:

```cpp
QString getUserName() const;
void setUserName(const QString &name);
```

Esto es importante porque se pueden validar los datos antes de guardarlos.

## Validación de entradas

La aplicación valida las entradas del usuario en `main.cpp`. También se agregaron validaciones en `UserProfile.cpp` para evitar nombres vacíos y modelos inválidos.

Ejemplos de validación:

- El menú solo acepta números válidos.
- El nombre no puede estar vacío.
- El modelo debe ser una opción permitida.
- La pregunta no puede estar vacía.

## Conclusión de la argumentación

El diseño cumple con los conceptos principales de programación orientada a objetos porque usa clases con responsabilidades claras, datos privados, métodos públicos, herencia, polimorfismo, sobrecarga, sobreescritura y una clase abstracta. Además, el programa tiene una aplicación principal que demuestra que las clases funcionan correctamente.
