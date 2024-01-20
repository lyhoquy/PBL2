#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

// Lớp MainWindow kế thừa từ QMainWindow để tạo giao diện chính
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
    {
        // Tạo các widget
        QLabel *nameLabel = new QLabel("Tên:");
        QLineEdit *nameLineEdit = new QLineEdit();
        QLabel *ageLabel = new QLabel("Tuổi:");
        QLineEdit *ageLineEdit = new QLineEdit();
        QLabel *contactLabel = new QLabel("Số liên hệ:");
        QLineEdit *contactLineEdit = new QLineEdit();
        QLabel *emailLabel = new QLabel("Email:");
        QLineEdit *emailLineEdit = new QLineEdit();
        QPushButton *addButton = new QPushButton("Thêm khách hàng");

        // Kết nối sự kiện nhấn nút "Thêm khách hàng" với slot addCustomer()
        connect(addButton, &QPushButton::clicked, this, &MainWindow::addCustomer);

        // Tạo layout và thêm các widget vào layout
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(nameLabel);
        layout->addWidget(nameLineEdit);
        layout->addWidget(ageLabel);
        layout->addWidget(ageLineEdit);
        layout->addWidget(contactLabel);
        layout->addWidget(contactLineEdit);
        layout->addWidget(emailLabel);
        layout->addWidget(emailLineEdit);
        layout->addWidget(addButton);

        // Tạo widget chính và đặt layout vào widget chính
        QWidget *centralWidget = new QWidget();
        centralWidget->setLayout(layout);

        // Đặt widget chính là widget chính của MainWindow
        setCentralWidget(centralWidget);
    }

private slots:
    void addCustomer()
    {
        QString name = nameLineEdit->text();
        QString age = ageLineEdit->text();
        QString contactNumber = contactLineEdit->text();
        QString email = emailLineEdit->text();

        // Xử lý logic để thêm khách hàng vào hệ thống
        // Ghi chi tiết khách hàng vào tệp registration_history.txt

        QFile file("registration_history.txt");
        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "Name: " << name << "\n";
            out << "Age: " << age << "\n";
            out << "Contact Number: " << contactNumber << "\n";
            out << "Email: " << email << "\n\n";
            file.close();
        }
    }

private:
    QLineEdit *nameLineEdit;
    QLineEdit *ageLineEdit;
    QLineEdit *contactLineEdit;
    QLineEdit *emailLineEdit;
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}