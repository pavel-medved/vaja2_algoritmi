FROM ubuntu:latest

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*

RUN cmake -Bbuild -DCMAKE_BUILD_TYPE=Release .

RUN cmake --build build

CMD ["./build/main", "test_sunday", "znanstveniki", "/app/cmake-build-debug/test-besedilo.txt"]
