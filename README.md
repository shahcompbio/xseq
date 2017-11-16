# Description
Cancer driver mutations control outcomes indirectly through intermediate phenotypes, e.g., gene expression and protein expression. xseq is a probabilistic model which aims to encode the impact of somatic mutations on gene expression profiles. The output can be used to identify mutations in cancer genomes that likely have a functional role in altering normal biological processes leading to the malignant phenotype. The model is a generative hierarchical Bayes approach which has as input three observed quantities: a patient-gene gene expression matrix, a patient-gene mutation matrix and graph containing known interactions between genes (e.g. from pathway databases). The model outputs the posterior probability of a mutation influencing expression, at a population level the posterior of all the mutations of a gene influence expression, and the posterior probabilities of the genes connected to a mutated gene as being up-regulated, down-regulated or neutral in a patient. As such, this software can systematically evaluate entire complements of mutations in a tumour and predict the degree to which they alter gene expression. 

xseq has been tested on Mac OS version 10.6.8, and Linux CentOS release 5.11

Questions or comments on the software or the model should be directed to Jiarui Ding ( jiaruid at cs dot ubc dot ca) or Sohrab Shah (sshah at bccrc dot ca)

# Publication
[J. Ding, M.K.McConechy, H.M.Horlings, G. Ha, F. Chan, T. Funnell, S. Mullaly, J. Reimand, A. Bashashati, G.D.Bader, D. Huntsman, S. Aparicio, A. Condon, S. P. Shah. Systematic analysis of somatic mutations impacting gene expression in twelve tumour types. Nature Communications Article number:8554 doi:10.1038/ncomms9554](https://www.nature.com/articles/ncomms9554)

# Supplementary Materials:
Supplementary Data 1: [The collected 603 bona fide driver genes.](http://compbio.bccrc.ca/software/xseq/pbio-bccrc.sites.olt.ubc.ca/files/2015/12/supp_data1_bona_fide_cancer_driver_gene.txt)

Supplementary Data 2: [The 65 xseq predicted genes with cis-effect loss-of-function mutations.](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/12/supp_data2_cis_gene.txt)

Supplementary Data 3: [The 131 candidate tumour suppressor genes and their P(TSG) probabilities.](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/12/supp_data3_tsg_candidate.txt)

Supplementary Data 4: [The 60 xseq predicted trans-effect genes. These trans-effect genes were annotated as bona fide cancer driver genes.](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/12/supp_data4_trans_putative.txt)

Supplementary Data 5: “The 89 novel xseq predicted trans-effect genes. The 89 novel xseq pre-dicted trans-effect genes which were not significantly mutated6 and were not annotated as bona fide cancer driver genes.”: Supplementary Data 5: The 89 novel xseq predicted trans-effect genes. The 89 novel xseq pre-dicted trans-effect genes which were not significantly mutated6 and were not annotated as bona fide cancer driver genes.

Supplementary Data 6: [Enriched pathways and gene ontology terms in the novel trans-effect genes.](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/12/supp_data6_trans_novel_pathway_enrich.txt)

Supplementary Data 7: [Genes stably up-regulated associated with mutations across tumour types.](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/12/supp_data7_stable_mut_up_regulation_gene_pair.txt)

Supplementary Data 8: [Genes stably down-regulated associated with mutations across tumour types.](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/12/supp_data8_stable_mut_down_regulation_gene_pair.txt)

# Used in:
[Chan FC, Telenius A, Healy S, Ben-Neriah S, Mottok A, Lim R, Drake M, Hu S, Ding J, Ha G, Scott DW, Kridel R, Bashashati A, Rogic S, Johnson N, Morin RD, Rimsza LM, Sehn L, Connors JM, Marra MA, Gascoyne RD, Shah SP, Steidl C. An RCOR1 loss-associated gene expression signature identifies a prognostically significant DLBCL subgroup. Blood. 2015 Feb 5;125(6):959-66. doi: 10.1182/blood-2013-06-507152. Epub 2014 Nov 13. PubMed PMID: 25395426.](https://www.ncbi.nlm.nih.gov/pubmed/25395426)

[Mathelier A, Lefebvre C, Zhang AW, Arenillas DJ, Ding J, Wasserman WW, Shah SP. Cis-regulatory somatic mutations and gene-expression alteration in B-cell lymphomas. Genome Biol. 2015 Apr 23;16:84. doi: 10.1186/s13059-015-0648-7. PubMed PMID: 25903198](https://www.ncbi.nlm.nih.gov/pubmed/25903198)

# Download
The updated version is on CRAN [xseq package](https://cran.r-project.org/web/packages/xseq/)

You can download the influence graph as a text file from [influence_graph.txt](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/05/influence_graph.txt) or as an R object from [influence_graph.rda](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/05/influence_graph.zip)

The high-quality [human interactome database](http://compbio-bccrc.sites.olt.ubc.ca/files/2015/09/high_quality_PPI.txt) used for validation purpose (downloaded from [here](http://interactome.dfci.harvard.edu/H_sapiens/index.php?page=download))
