.PHONY: all clean install

BUILD_DIR := build
INSTALL_DIR := ~/include

all: $(BUILD_DIR)/Makefile
	@$(MAKE) -C $(BUILD_DIR)

$(BUILD_DIR)/Makefile:
	@mkdir -p $(BUILD_DIR)
	@cd $(BUILD_DIR) && cmake -DCMAKE_INSTALL_PREFIX=$(INSTALL_DIR) ..

install: all
	@$(MAKE) -C $(BUILD_DIR) install

clean:
	@rm -rf $(BUILD_DIR)