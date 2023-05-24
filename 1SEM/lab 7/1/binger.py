# открываем бинарный файл для записи
with open("file.bin", "wb") as file:
    while True:
        # запрашиваем у пользователя фразу для записи в файл
        phrase_to_write = input("Введите фразу для записи в файл или нажмите Enter для завершения: ")
        if not phrase_to_write:
            # если пользователь нажал Enter, завершаем ввод фраз
            break
        
        # преобразуем фразу в байты и записываем их в файл
        byte_data = phrase_to_write.encode()
        file.write(byte_data)
