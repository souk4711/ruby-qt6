// clang-format off

#include "qapplication-rb.hpp"
#include <QApplication>

using namespace Rice;

Rice::Class rb_cQApplication;

QApplication *_newQApplication(std::vector<std::string> old_argv)
{
    std::vector<char *> argv;
    for (int i = 0; i < old_argv.size(); ++i)
    {
        argv.push_back(const_cast<char *>(old_argv[i].c_str()));
    }
    int argc = argv.size();
    return new QApplication(argc, argv.data());
}

void Init_QApplication(Rice::Module rb_mQt6QtWidgets)
{
    rb_mQt6QtWidgets.define_singleton_function("_new_qapplication", &_newQApplication, Arg("argv"));

    rb_cQApplication = // Qt6::QtWidgets::QApplication
        define_class_under<QApplication, QGuiApplication>(rb_mQt6QtWidgets, "QApplication")
            .define_constructor(Constructor<QApplication, int &, char **>(), Arg("argc"), Arg("argv"))
            .define_singleton_function("exec", &QApplication::exec);
}
