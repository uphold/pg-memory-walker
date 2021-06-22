MODULES = walker
DATA_built = walker.sql

PG_CONFIG = PG_CONFIG
PGXS := $(shell $(PG_CONFIG) --pgxs)
CFLAGS += -g
include $(PGXS)
