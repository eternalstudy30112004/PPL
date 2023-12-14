#include <gtk/gtk.h>

GtkWidget *entry;

void on_button_clicked(GtkWidget *widget, gpointer data) {
    const char *text = gtk_button_get_label(GTK_BUTTON(widget));
    const char *current_text = gtk_entry_get_text(GTK_ENTRY(entry));

    if (strcmp(text, "=") == 0) {
        // Evaluate the expression and display the result
        GtkExpression *expression = gtk_expression_new(current_text);
        if (expression != NULL) {
            gtk_entry_set_text(GTK_ENTRY(entry), gtk_expression_evaluate(expression));
            gtk_expression_free(expression);
        }
    } else {
        // Append the clicked button's label to the entry text
        char *new_text = g_strdup_printf("%s%s", current_text, text);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
        g_free(new_text);
    }
}

void create_button(GtkWidget *grid, const char *label, int row, int column, int width, int height) {
    GtkWidget *button = gtk_button_new_with_label(label);
    gtk_grid_attach(GTK_GRID(grid), button, column, row, width, height);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Simple Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_container_add(GTK_CONTAINER(window), grid);

    entry = gtk_entry_new();
    gtk_entry_set_alignment(GTK_ENTRY(entry), 1.0);
    gtk_entry_set_width_chars(GTK_ENTRY(entry), 20);
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 4, 1);

    create_button(grid, "1", 1, 0, 1, 1);
    create_button(grid, "2", 1, 1, 1, 1);
    create_button(grid, "3", 1, 2, 1, 1);
    create_button(grid, "+", 1, 3, 1, 1);

    create_button(grid, "4", 2, 0, 1, 1);
    create_button(grid, "5", 2, 1, 1, 1);
    create_button(grid, "6", 2, 2, 1, 1);
    create_button(grid, "-", 2, 3, 1, 1);

    create_button(grid, "7", 3, 0, 1, 1);
    create_button(grid, "8", 3, 1, 1, 1);
    create_button(grid, "9", 3, 2, 1, 1);
    create_button(grid, "*", 3, 3, 1, 1);

    create_button(grid, "0", 4, 0, 1, 1);
    create_button(grid, ".", 4, 1, 1, 1);
    create_button(grid, "=", 4, 2, 1, 1);
    create_button(grid, "/", 4, 3, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
