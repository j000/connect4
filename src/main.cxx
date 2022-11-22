#include <QGuiApplication>
#include <QQmlApplicationEngine>

auto main(int argc, char** argv) -> int
{
	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine{};
	auto mainWindow{QStringLiteral("qrc:/windows/main.qml")};
	engine.load(mainWindow);

	return app.exec();
}
