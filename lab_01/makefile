# ============================================
#   папки
# ============================================

SRC_DIR := src
INC_DIR := inc
BUILD_DIR := build
RELEASE_DIR := release

# ============================================
#   исходники
# ============================================

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# ============================================
#   компилятор и флаги
# ============================================

CXX := g++
CXX_FLAGS := -std=c++23 -I$(INC_DIR) -Wall -Werror -Wpedantic -Wextra

# ============================================
#   цели
# ============================================

all: clean app

app: $(RELEASE_DIR)/app.exe

clean: 
	rm -rf $(BUILD_DIR) $(RELEASE_DIR)

# ============================================
#   сборка
# ============================================

$(RELEASE_DIR)/app.exe: $(OBJECTS) | $(RELEASE_DIR)
	$(CXX) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

$(BUILD_DIR) $(RELEASE_DIR):
	mkdir -p $@