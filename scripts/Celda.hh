#pragma once

class Celda {
    public:
        Celda(int fila, int columna): fila_(fila), columna_(columna) {}
        Celda(const Celda&) = default;
    private:
        int fila_;
        int columna_;
};