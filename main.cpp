#include <QCoreApplication>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonObject>

#include "PersistenceManager.h"
#include "IDataStorage.h"
#include "UserProfile.h"

QString readNonEmptyText(const QString &message)
{
    QTextStream in(stdin);
    QTextStream out(stdout);

    QString text;

    do
    {
        out << message;
        out.flush();

        text = in.readLine().trimmed();

        if(text.isEmpty())
        {
            out << "Entrada inválida. El texto no puede estar vacío.\n";
        }
    }
    while(text.isEmpty());

    return text;
}

int readOption(int minValue, int maxValue)
{
    QTextStream in(stdin);
    QTextStream out(stdout);

    bool ok = false;
    int option = 0;

    do
    {
        out << "Elige una opción: ";
        out.flush();

        QString input = in.readLine().trimmed();
        option = input.toInt(&ok);

        if(!ok)
        {
            out << "Entrada inválida. Escribe un número.\n";
        }
        else if(option < minValue || option > maxValue)
        {
            out << "Opción fuera de rango. Intenta otra vez.\n";
            ok = false;
        }
    }
    while(!ok);

    return option;
}

QString chooseModel()
{
    QTextStream out(stdout);

    out << "Elige tu modelo preferido:\n";
    out << "1. gemma3:4b\n";
    out << "2. llama3.2\n";
    out << "3. mistral\n";

    int option = readOption(1, 3);

    if(option == 1)
    {
        return "gemma3:4b";
    }
    else if(option == 2)
    {
        return "llama3.2";
    }

    return "mistral";
}

void showMenu()
{
    QTextStream out(stdout);

    out << "\n=====================================\n";
    out << "        AGENTE PETE\n";
    out << "=====================================\n";
    out << "1. Configurar perfil\n";
    out << "2. Mostrar perfil actual\n";
    out << "3. Guardar conversación\n";
    out << "4. Guardar pregunta sin respuesta\n";
    out << "5. Mostrar historial\n";
    out << "6. Salir\n";
}

void configureProfile(IDataStorage *storage)
{
    QTextStream out(stdout);

    QString name = readNonEmptyText("Escribe tu nombre: ");
    QString model = chooseModel();

    UserProfile profile;
    profile.setUserName(name);
    profile.setPreferredModel(model);

    if(storage->saveUserProfile(profile))
    {
        out << "Perfil guardado correctamente.\n";
    }
    else
    {
        out << "No se pudo guardar el perfil.\n";
    }
}

void showProfile(IDataStorage *storage)
{
    QTextStream out(stdout);

    UserProfile profile = storage->loadUserProfile();

    out << "\nUsuario: " << profile.getUserName() << "\n";
    out << "Modelo preferido: " << profile.getPreferredModel() << "\n";
}

void saveFullConversation(IDataStorage *storage)
{
    QTextStream out(stdout);

    QString prompt = readNonEmptyText("Escribe tu pregunta: ");

    QString response = "Esta es una respuesta generada por Agente PETE.";

    out << "Respuesta simulada: " << response << "\n";

    if(storage->saveConversation(prompt, response))
    {
        out << "Conversación guardada correctamente.\n";
    }
    else
    {
        out << "No se pudo guardar la conversación.\n";
    }
}

void saveQuestionWithoutResponse(PersistenceManager &manager)
{
    QTextStream out(stdout);

    QString prompt = readNonEmptyText("Escribe la pregunta que deseas guardar: ");

    // Aquí se usa la sobrecarga de saveConversation.
    if(manager.saveConversation(prompt))
    {
        out << "Pregunta guardada sin respuesta.\n";
    }
    else
    {
        out << "No se pudo guardar la pregunta.\n";
    }
}

void showHistory(IDataStorage *storage)
{
    QTextStream out(stdout);

    QJsonArray history = storage->loadHistory();

    if(history.isEmpty())
    {
        out << "No hay conversaciones guardadas.\n";
        return;
    }

    out << "\nHistorial de conversaciones:\n";

    for(int i = 0; i < history.size(); i++)
    {
        QJsonObject item = history[i].toObject();

        out << "\n" << i + 1 << ") Fecha: "
            << item["date"].toString() << "\n";
        out << "Pregunta: "
            << item["prompt"].toString() << "\n";
        out << "Respuesta: "
            << item["response"].toString() << "\n";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream out(stdout);

    PersistenceManager manager;

    // Aquí se aplica polimorfismo.
    IDataStorage *storage = &manager;

    if(!storage->initialize())
    {
        out << "No se pudo inicializar el almacenamiento.\n";
        return 1;
    }

    int option = 0;

    do
    {
        showMenu();
        option = readOption(1, 6);

        switch(option)
        {
        case 1:
            configureProfile(storage);
            break;
        case 2:
            showProfile(storage);
            break;
        case 3:
            saveFullConversation(storage);
            break;
        case 4:
            saveQuestionWithoutResponse(manager);
            break;
        case 5:
            showHistory(storage);
            break;
        case 6:
            out << "Saliendo del programa.\n";
            break;
        }
    }
    while(option != 6);

    return 0;
}
