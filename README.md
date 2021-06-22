# Postgresql Memory Walker

This is a small extension that simply walks the chain of memory contexts from
`TopMemoryContext` on down and uses `elog(NOTICE)` to give a list of memory
contexts in the tree and their inclusive sizes.

## Building

In order to build, it is required that you have a copy of `pg_config` in your
path.  If you are running Linux, this will likely be from a development package.

```
$ make
```

## Installing

```
$ make install
```

## Using

```
# CREATE OR REPLACE FUNCTION walker() RETURNS VOID
  AS 'MODULE_PATHNAME', 'walker'
  LANGUAGE C STRICT;
# SELECT walker();
```

### Example Output

```
uphold=# select walker();
NOTICE:  TopMemoryContext[(null)] (68704 / 14560)
NOTICE:   dynahash[CFuncHash] (8192 / 552)
NOTICE:   dynahash[pgstat TabStatusArray lookup hash table] (8192 / 1448)
NOTICE:   TopTransactionContext[(null)] (8192 / 7736)
NOTICE:   RowDescriptionContext[(null)] (8192 / 6888)
NOTICE:   MessageContext[(null)] (16384 / 6160)
NOTICE:   dynahash[Operator class cache] (8192 / 552)
NOTICE:   dynahash[smgr relation table] (16384 / 4592)
NOTICE:   TransactionAbortContext[(null)] (32768 / 32504)
NOTICE:   dynahash[Portal hash] (8192 / 552)
NOTICE:   TopPortalContext[(null)] (8192 / 7656)
NOTICE:    PortalContext[] (1024 / 592)
NOTICE:     ExecutorState[(null)] (8192 / 4032)
NOTICE:      printtup[(null)] (8192 / 7928)
NOTICE:      pgaudit stack context[(null)] (8192 / 7784)
NOTICE:      ExprContext[(null)] (8192 / 7928)
NOTICE:   dynahash[Relcache by OID] (16384 / 3504)
NOTICE:   CacheMemoryContext[(null)] (524288 / 128328)
NOTICE:    index info[pg_db_role_setting_databaseid_rol_index] (2048 / 496)
NOTICE:    index info[pg_opclass_am_name_nsp_index] (3072 / 1160)
NOTICE:    index info[pg_foreign_data_wrapper_name_index] (2048 / 952)
NOTICE:    index info[pg_enum_oid_index] (1024 / 0)
NOTICE:    index info[pg_class_relname_nsp_index] (2048 / 688)
NOTICE:    index info[pg_foreign_server_oid_index] (1024 / 0)
NOTICE:    index info[pg_publication_pubname_index] (1024 / 0)
NOTICE:    index info[pg_statistic_relid_att_inh_index] (3072 / 1128)
NOTICE:    index info[pg_cast_source_target_index] (2048 / 688)
NOTICE:    index info[pg_language_name_index] (1024 / 0)
NOTICE:    index info[pg_transform_oid_index] (1024 / 0)
NOTICE:    index info[pg_collation_oid_index] (1024 / 0)
NOTICE:    index info[pg_amop_fam_strat_index] (3072 / 1096)
NOTICE:    index info[pg_index_indexrelid_index] (2048 / 824)
NOTICE:    index info[pg_ts_template_tmplname_index] (2048 / 688)
NOTICE:    index info[pg_ts_config_map_index] (3072 / 1160)
NOTICE:    index info[pg_opclass_oid_index] (2048 / 824)
NOTICE:    index info[pg_foreign_data_wrapper_oid_index] (2048 / 952)
NOTICE:    index info[pg_event_trigger_evtname_index] (1024 / 0)
NOTICE:    index info[pg_statistic_ext_name_index] (2048 / 688)
NOTICE:    index info[pg_publication_oid_index] (1024 / 0)
NOTICE:    index info[pg_ts_dict_oid_index] (1024 / 0)
NOTICE:    index info[pg_event_trigger_oid_index] (1024 / 0)
NOTICE:    index info[pg_conversion_default_index] (3072 / 1096)
NOTICE:    index info[pg_operator_oprname_l_r_n_index] (3072 / 1096)
NOTICE:    index info[pg_trigger_tgrelid_tgname_index] (2048 / 688)
NOTICE:    index info[pg_enum_typid_label_index] (2048 / 688)
NOTICE:    index info[pg_ts_config_oid_index] (1024 / 0)
NOTICE:    index info[pg_user_mapping_oid_index] (1024 / 0)
NOTICE:    index info[pg_opfamily_am_name_nsp_index] (3072 / 1160)
NOTICE:    index info[pg_foreign_table_relid_index] (1024 / 0)
NOTICE:    index info[pg_type_oid_index] (2048 / 824)
NOTICE:    index info[pg_aggregate_fnoid_index] (1024 / 0)
NOTICE:    index info[pg_constraint_oid_index] (1024 / 0)
NOTICE:    index info[pg_rewrite_rel_rulename_index] (2048 / 688)
NOTICE:    index info[pg_ts_parser_prsname_index] (2048 / 688)
NOTICE:    index info[pg_ts_config_cfgname_index] (2048 / 688)
NOTICE:    index info[pg_ts_parser_oid_index] (1024 / 0)
NOTICE:    index info[pg_publication_rel_prrelid_prpubid_index] (2048 / 656)
NOTICE:    index info[pg_operator_oid_index] (1024 / 0)
NOTICE:    index info[pg_namespace_nspname_index] (2048 / 824)
NOTICE:    index info[pg_ts_template_oid_index] (1024 / 0)
NOTICE:    index info[pg_amop_opr_fam_index] (3072 / 1160)
NOTICE:    index info[pg_default_acl_role_nsp_obj_index] (3072 / 1128)
NOTICE:    index info[pg_collation_name_enc_nsp_index] (3072 / 1160)
NOTICE:    index info[pg_publication_rel_oid_index] (1024 / 0)
NOTICE:    index info[pg_range_rngtypid_index] (1024 / 0)
NOTICE:    index info[pg_ts_dict_dictname_index] (2048 / 688)
NOTICE:    index info[pg_type_typname_nsp_index] (2048 / 688)
NOTICE:    index info[pg_opfamily_oid_index] (1024 / 0)
NOTICE:    index info[pg_statistic_ext_oid_index] (1024 / 0)
NOTICE:    index info[pg_statistic_ext_data_stxoid_index] (2048 / 952)
NOTICE:    index info[pg_class_oid_index] (2048 / 824)
NOTICE:    index info[pg_proc_proname_args_nsp_index] (3072 / 1000)
NOTICE:    index info[pg_partitioned_table_partrelid_index] (2048 / 952)
NOTICE:    index info[pg_transform_type_lang_index] (2048 / 688)
NOTICE:    index info[pg_attribute_relid_attnum_index] (2048 / 448)
NOTICE:    index info[pg_proc_oid_index] (2048 / 824)
NOTICE:    index info[pg_language_oid_index] (1024 / 0)
NOTICE:    index info[pg_namespace_oid_index] (1024 / 0)
NOTICE:    index info[pg_amproc_fam_proc_index] (3072 / 776)
NOTICE:    index info[pg_foreign_server_name_index] (1024 / 0)
NOTICE:    index info[pg_attribute_relid_attnam_index] (2048 / 688)
NOTICE:    index info[pg_conversion_oid_index] (1024 / 0)
NOTICE:    index info[pg_user_mapping_user_server_index] (2048 / 656)
NOTICE:    index info[pg_subscription_rel_srrelid_srsubid_index] (2048 / 656)
NOTICE:    index info[pg_sequence_seqrelid_index] (1024 / 0)
NOTICE:    index info[pg_conversion_name_nsp_index] (2048 / 688)
NOTICE:    index info[pg_authid_oid_index] (2048 / 824)
NOTICE:    index info[pg_auth_members_member_role_index] (2048 / 656)
NOTICE:    index info[pg_subscription_oid_index] (1024 / 0)
NOTICE:    index info[pg_tablespace_oid_index] (1024 / 0)
NOTICE:    index info[pg_shseclabel_object_index] (3072 / 1160)
NOTICE:    index info[pg_replication_origin_roname_index] (2048 / 952)
NOTICE:    index info[pg_database_datname_index] (2048 / 824)
NOTICE:    index info[pg_subscription_subname_index] (2048 / 688)
NOTICE:    index info[pg_replication_origin_roiident_index] (2048 / 952)
NOTICE:    index info[pg_auth_members_role_member_index] (2048 / 656)
NOTICE:    index info[pg_database_oid_index] (2048 / 824)
NOTICE:    index info[pg_authid_rolname_index] (2048 / 824)
NOTICE:   WAL record construction[(null)] (49768 / 6360)
NOTICE:   dynahash[PrivateRefCount] (8192 / 2616)
NOTICE:   MdSmgr[(null)] (8192 / 7904)
NOTICE:   dynahash[LOCALLOCK hash] (8192 / 552)
NOTICE:   dynahash[Timezones] (104120 / 2616)
NOTICE:   ErrorContext[(null)] (8192 / 7928)
 walker
--------

(1 row)

Time: 9.556 ms
```
