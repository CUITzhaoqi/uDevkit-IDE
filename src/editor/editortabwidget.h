#ifndef EDITORTABWIDGET_H
#define EDITORTABWIDGET_H

#include <QStack>
#include <QMap>
#include <QTabWidget>

#include <project/projecticonprovider.h>

#include "editor.h"
#include "project/project.h"

class EditorTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    EditorTabWidget(Project *project);

    void addEditor(Editor *editor);
    Editor *currentEditor() const;
    QString currentFilePath() const;
    Editor *editor(int i) const;

public slots:
    void openFileEditor(const QString &url);
    void closeFileEditor(const QString &filePath);

    int closeEditor(int id=-1);
    int closeAllEditors();
    void saveCurrentEditor();
    void saveAllEditors();

    void switchHeader();

    void nextTab();
    void previousTab();

signals:
    void editorChange(Editor *editor);
    void currentEditorModified(Editor *editor);
    void currentFileChanged(QString filePath);
    void statusChanged(QString status);

protected slots:
    void updateTab();
    void activeTab(int id);
    void changeStatus(QString status);

protected:
    bool eventFilter(QObject *o, QEvent *e);
    void registerAction();

    Project *_project;
    QStack<int> _activedTab;
    QMap<QString, Editor* > _mapPathEditor;
    ProjectIconProvider *_iconProvider;
};

#endif // EDITORTABWIDGET_H
