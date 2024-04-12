FROM ubuntu:latest

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*

RUN cmake -Bbuild -DCMAKE_BUILD_TYPE=Release .

RUN cmake --build build

CMD ["./build/main", 0, "znanstveniki", "/app/cmake-build-debug/test-besedilo.txt"]
